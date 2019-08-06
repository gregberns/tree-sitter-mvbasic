module.exports = grammar({
  name: 'the_language_name',

  rules: {
    // The production rules of the context-free grammar
    source_file: $ => repeat($._definition),
  
    
    _newline: $ => /\\n/,

    _definition: $ => choice(
      $._for,
      $._statement,
    ),

    _statement: $ => choice(
      $.declaration,
      // TODO: other kinds of statements
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

    _for: $ => seq(
      'FOR',
      $._expression,
      'TO',
      $.identifier,
      $._newline,
      repeat($._statement),
      'NEXT',
      $.identifier,
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


    _expression: $ => choice(
      $.identifier,
      $.number,
      $.bool,

      
    ),

    identifier: $ => /[A-Z]+/,

    number: $ => /\d+/,

    bool: $ => choice($._true, $._false),
    _true: $ => token('TRUE'),
    _false: $ => token('FALSE'),


    _expression: $ => choice(
      // $.comparison_operator,
      // $.not_operator,
      $.boolean_operator,
      // $.await,
      // $.lambda,
      $._primary_expression,
      // $.conditional_expression,
      // $.named_expression
    ),

    _primary_expression: $ => choice(
      $.binary_operator,
      // $.identifier,
      // $.keyword_identifier,
      // $.string,
      // $.concatenated_string,
      // $.integer,
      // $.float,
      // $.true,
      // $.false,
      // $.none,
      // $.unary_operator,
      // $.attribute,
      // $.subscript,
      // $.call,
      // $.list,
      // $.list_comprehension,
      // $.dictionary,
      // $.dictionary_comprehension,
      // $.set,
      // $.set_comprehension,
      // $.tuple,
      // $.parenthesized_expression,
      // $.generator_expression,
      // $.ellipsis
    ),









    // function_definition: $ => seq(
    //   'func',
    //   $.identifier,
    //   $.parameter_list,
    //   $._type,
    //   $.block
    // ),

    // parameter_list: $ => seq(
    //   '(',
    //   optional(
    //     $.identifier
    //   ),
    //   optional(
    //     repeat(
    //       seq(
    //         ',',
    //         $.identifier,
    //       )
    //     ),
    //   ),
    //   optional(','),
    //   ')'
    // ),

    // _type: $ => choice(
    //   'bool'
    //   // TODO: other kinds of types
    // ),

    // block: $ => seq(
    //   '{',
    //   repeat($._statement),
    //   '}'
    // ),


    // if_statement: $ => seq (
    //   'if',
    //   $._expression,
    //   $.block,
    //   optional(
    //     $.else_statement,
    //   )
    // ),

    // else_statement: $ => seq(
    //   'else',
    //   $.block,
    // ),

    // return_statement: $ => seq(
    //   'return',
    //   $._expression,
    //   ';'
    // ),


  }
});
