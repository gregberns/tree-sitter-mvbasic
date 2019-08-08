const PREC = {
  call: 14,
  field: 13,
  unary: 11,
  multiplicative: 10,
  additive: 9,
  shift: 8,
  bitand: 7,
  bitxor: 6,
  bitor: 5,
  comparative: 4,
  and: 3,
  or: 2,
  range: 1,
  assign: 0,
  closure: -1,
}

module.exports = grammar({
  name: 'mvbasic',

  // externals: $ => [
  //   $._line_break,

  //   // Delimited literals
  //   $._string_start,
  //   $._string_content,
  // ],

  rules: {
    // The production rules of the context-free grammar
    source_file: $ => repeat($._definition),
  
    
    _newline: $ => /\\n/,

    _definition: $ => choice(
      $._statement,
    ),

    _statement: $ => choice(
      $.declaration,
      $.for_loop,
      $.if_statement,
      $._expression,
    ),

    declaration: $ => seq(
      $.identifier,
      '=',
      choice(
        $._expression,
        $.method_call,
      ),
      // $._newline,
    ),

    _expression: $ => choice(
      $.identifier,
      $.string,
      $.number,
      $.bool,
      $.unary_expression,
      $.binary_expression,
    ),

    identifier: $ => /[A-Z]+/,

    number: $ => /\d+/,

    bool: $ => choice($._true, $._false),
    _true: $ => token('TRUE'),
    _false: $ => token('FALSE'),

    string: $ => choice(
      seq('"', repeat(choice(/[^"\n]/, /\\(.|\n)/)), '"'),
      seq(`'`, repeat(choice(/[^'\n]/, /\\(.|\n)/)), `'`),
      seq(`\\`, repeat(choice(/[^\\\n]/, /(.|\n)/)), `\\`),
      // seq(`'`, optional($._string_content), `'`),
      // seq(`"`, optional($._string_content), `"`),
      // seq(`\\`, optional($._string_content), `\\`),
    ),

    unary_expression: $ => prec(PREC.unary, seq(
      choice('+', '-', 'NOT', 'ALPHA', 'NUM'),
      $._expression
    )),

    binary_expression: $ => choice(
      prec.left(PREC.multiplicative, seq($._expression, choice('*', '/', '%'), $._expression)),
      prec.left(PREC.additive, seq($._expression, choice('+', '-'), $._expression)),
      prec.left(PREC.additive, seq($._expression, choice(':', 'CAT'), $._expression)),
      prec.left(PREC.comparative, seq($._expression, 
        choice(
          '==', 'EQ', //need to correct == to =, is a parse issue
          '#', 'NE', 
          '><', '<>', 
          '<', 'LT', 
          '>', 'GT', 
          '<=', '=<', 'LE', 
          '>=', '=>', '#<', 'GE'), $._expression)),
      // prec.left(PREC.shift, seq($._expression, choice('<<', '>>'), $._expression)),
      prec.left(PREC.and, seq($._expression, choice('AND', '&'), $._expression)),
      prec.left(PREC.or, seq($._expression, choice('OR', '|'), $._expression)),
      // prec.left(PREC.bitor, seq($._expression, '|', $._expression)),
      // prec.left(PREC.bitand, seq($._expression, '&', $._expression)),
      // prec.left(PREC.bitxor, seq($._expression, '^', $._expression)),
      // $.assignment_expression,
      // $.compound_assignment_expr,
      // $.type_cast_expression
    ),



    for_loop: $ => seq(
      'FOR',
      $.declaration,
      'TO',
      $.identifier,
      // [STEP increment]
      // $._newline,
      repeat($._statement),
      // $.declaration,
      // $._newline,
      'NEXT',
      // $._newline,
      // optional($.identifier),
    ),

    method_call: $ => seq(
      $.identifier,
      '(',
      $.identifier,
      ')',
    ),

    // named_expression: $ => seq(
    //   $.identifier,
    //   ':=',
    //   $._expression
    // ),


    if_statement: $ => seq (
      'IF',
      $._expression,
      optional(
        $.then_statement,
      ),
      optional(
        $.else_statement,
      ),
      'END'
    ),

    then_statement: $ => seq(
      'THEN',
      repeat($._statement),
    ),

    else_statement: $ => seq(
      'ELSE',
      repeat($._statement),
    ),
    

    

  }
});
