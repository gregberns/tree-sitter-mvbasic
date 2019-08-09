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
  concat: 2,
  range: 1,
  comment: 1,
  assign: 0,
  closure: -1,
}

// To Do
// * indentifier<integer> `NOT.FOREIGN<1> = 'USA,US'`
// * CONVERT statement `CONVERT ',' TO @VM IN NOT.FOREIGN`

// Can't solve:
// * float
// * comments starting with '*' conflict with multiply operator

module.exports = grammar({
  name: 'mvbasic',

  extras: $ => [
    $.comment,
    ///\s+/
    /\s|\\\n/
  ],

  rules: {
    // The production rules of the context-free grammar
    source_file: $ => repeat($._definition),
  
    _newline: $ => /\\n/,

    _semicolon: $ => ';',

    _definition: $ => choice(
      $._statement,
    ),

    _statement: $ => choice(
      $.comment,
      $.declaration,
      $._expression,
      $.for_loop,
      $.loop_statement,
      $.if_statement,
      $.print_statement,
      $.input_statement,
      $.call_statement,
      $.continue_statement,
      $.while_statement,
      $.until_statement,
      $.goto_statement,
      $.case_statement,
      $.stop_statement,
      $.open_statement,
      $.dim_statement,
      $.convert_statement,
    ),

    _expression: $ => choice(
      $.identifier,
      $.string,
      $.integer,
      $.bool,
      $.unary_expression,
      $.binary_expression,
      $.method_call,
    ),

    identifier: $ => /[A-Z.]+/,

    comment: $ => token(prec(PREC.comment, choice(
      seq( '!', /.*/),
      seq('$*', /.*/),
      // seq('*', /.*/), // Can't figure out how to support this - conflicts with * multiply
      seq('REM', /.*/),
    ))),

    integer: $ => /\d{1,19}/,

    float: $ => /\d(_?\d)*(\.\d)?(_?\d)*([eE][\+-]?\d(_?\d)*)?/,

    bool: $ => choice($._true, $._false),
    _true: $ => token('TRUE'),
    _false: $ => token('FALSE'),

    string: $ => choice(
      seq('"', repeat(choice(/[^"\n]/, /\\(.|\n)/)), '"'),
      seq(`'`, repeat(choice(/[^'\n]/, /\\(.|\n)/)), `'`),
      seq(`\\`, repeat(choice(/[^\\\n]/, /(.|\n)/)), `\\`),
    ),

    unary_expression: $ => prec.right(PREC.unary, choice(
      ...[
        '-',
        '+',
        'NOT',
        'ALPHA',
        'NUM',
      ].map(operator => seq(operator, $._expression)))),

    binary_expression: $ => choice(
      prec.left(PREC.multiplicative, seq($._expression, choice('*', '/', '%'), $._expression)),
      prec.left(PREC.additive, seq($._expression, choice('+', '-'), $._expression)),
      //possible that the precidence needs to be changed here. arithmetic operators have greater precidence
      prec.left(PREC.concat, seq($._expression, choice(':', 'CAT'), $._expression)),
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

    declaration: $ => seq(
      $.identifier,
      '=',
      $._expression,
      optional($._semicolon),
    ),

    // assignment_expression: $ => prec.right(PREC.ASSIGN, seq(
    //   field('left', $._lhs_expression),
    //   '=',
    //   field('right', $._expression)
    // )),

    // augmented_assignment_expression: $ => prec.right(PREC.ASSIGN, seq(
    //   field('left', choice(
    //     $.member_expression,
    //     $.subscript_expression,
    //     alias($._reserved_identifier, $.identifier),
    //     $.identifier
    //   )),
    //   choice('+=', '-=', '*=', '/=', '%=', '^=', '&=', '|=', '>>=', '>>>=', '<<=', '**='),
    //   field('right', $._expression)
    // )),

    continue_statement: $ => 'CONTINUE',

    while_statement: $ => seq(
      'WHILE',
      $._expression,
      optional('DO')
    ),

    until_statement: $ => seq(
      'UNTIL',
      $._expression,
      optional('DO')
    ),

    for_loop: $ => seq(
      'FOR',
      $.declaration,
      'TO',
      $.identifier,
      // [STEP increment]
      optional(seq('STEP', $.integer)),
      repeat($._statement),
      
      'NEXT',
    ),

    loop_statement: $ => seq(
      'LOOP',
      optional(repeat($._statement)),
      'REPEAT',
    ),

    

    method_call: $ => prec(PREC.call, seq(
      $.identifier,
      $.parameter_list,
    )),

    parameter_list: $ => seq(
      '(',
      optional($._formal_parameter_list),
      ')'
    ),

    _formal_parameter_list: $ => commaSep1(choice(
      $.parameter,
    )),

    parameter: $ => seq(
      $._expression,
    ),

    if_statement: $ => prec.right(seq (
      'IF',
      $._expression,
      optional(
        $.then_statement,
      ),
      optional(
        $.else_statement,
      ),
      'END'
    )),

    then_statement: $ => seq(
      'THEN',
      repeat($._statement),
    ),

    else_statement: $ => seq(
      'ELSE',
      repeat($._statement),
    ),

    

    print_statement: $ => seq(
      'PRINT',
      $._expression,
      optional(':'),
    ),
    
    // More variations exist
    input_statement: $ => seq('INPUT', $.identifier),

    call_statement: $ => seq('CALL', $.method_call),

    goto_statement: $ => seq(
      choice('GO', 'GOTO', 'GO TO'),
      $.identifier,
      optional(':'),
    ),

    case_statement: $ => seq(
      'BEGIN CASE',
      repeat1($.case_case),
      'END CASE',
    ),

    case_case: $ => seq(
      'CASE',
      $._expression,
      repeat($._statement),
    ),

    stop_statement: $ => prec.right(seq(
      choice('STOP', 'STOPE', 'STOPM'),
      optional($._expression),
    )),

    open_statement: $ => seq(
      'OPEN',
      $.string,
      optional(seq(
        'TO',
        $.identifier
      )),
      // optional(seq(
      //   'ON ERROR',
      //   repeat($.statement),
      // )),
      optional(seq(
        'ELSE',
        repeat($._statement),
      )),
      ',',
      $.string,
    ),

    dim_statement: $ => seq(
      choice('DIM', 'DIMENSION'),
      $.identifier,
      '(',
      $.integer,
      optional($.integer),
      ')',
      //also can repeat the structure above 1 or more times
    ),

    convert_statement: $ => seq(
      'CONVERT',
      choice(
        seq(
          '(',
          $._expression,
          ',',
          $._expression,
          ',',
          $.identifier,
          ')'
        ),
        seq(
          $._expression,
          'TO',
          $._expression,
          'IN',
          $.identifier,
        ),
      ),
    ),

  }
});

function commaSep(rule) {
  return optional(commaSep1(rule))
}

function commaSep1(rule) {
  return seq(
    rule,
    repeat(seq(
      ',',
      rule
    ))
  )
}
