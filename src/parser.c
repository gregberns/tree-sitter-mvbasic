#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 10
#define STATE_COUNT 33
#define SYMBOL_COUNT 22
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8

enum {
  sym__newline = 1,
  anon_sym_EQ = 2,
  anon_sym_FOR = 3,
  anon_sym_TO = 4,
  anon_sym_NEXT = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RPAREN = 7,
  sym_identifier = 8,
  sym_number = 9,
  sym__true = 10,
  sym__false = 11,
  sym_source_file = 12,
  sym__definition = 13,
  sym__statement = 14,
  sym_declaration = 15,
  sym__for = 16,
  sym_method_call = 17,
  sym__expression = 18,
  sym_bool = 19,
  aux_sym_source_file_repeat1 = 20,
  aux_sym__for_repeat1 = 21,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__newline] = "_newline",
  [anon_sym_EQ] = "=",
  [anon_sym_FOR] = "FOR",
  [anon_sym_TO] = "TO",
  [anon_sym_NEXT] = "NEXT",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_identifier] = "identifier",
  [sym_number] = "number",
  [sym__true] = "_true",
  [sym__false] = "_false",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym__statement] = "_statement",
  [sym_declaration] = "declaration",
  [sym__for] = "_for",
  [sym_method_call] = "method_call",
  [sym__expression] = "_expression",
  [sym_bool] = "bool",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym__for_repeat1] = "_for_repeat1",
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FOR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TO] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NEXT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym__true] = {
    .visible = false,
    .named = true,
  },
  [sym__false] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__for] = {
    .visible = false,
    .named = true,
  },
  [sym_method_call] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_bool] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__for_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (lookahead == 0) ADVANCE(17);
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == ')') ADVANCE(26);
      if (lookahead == '=') ADVANCE(19);
      if (lookahead == 'F') ADVANCE(3);
      if (lookahead == 'N') ADVANCE(6);
      if (lookahead == 'T') ADVANCE(9);
      if (lookahead == '\\') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 1:
      if (lookahead == 0) ADVANCE(17);
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == 'F') ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 2:
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == 'N') ADVANCE(28);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 3:
      if (lookahead == 'A') ADVANCE(8);
      if (lookahead == 'O') ADVANCE(10);
      END_STATE();
    case 4:
      if (lookahead == 'E') ADVANCE(43);
      END_STATE();
    case 5:
      if (lookahead == 'E') ADVANCE(41);
      END_STATE();
    case 6:
      if (lookahead == 'E') ADVANCE(14);
      END_STATE();
    case 7:
      if (lookahead == 'F') ADVANCE(27);
      if (lookahead == 'T') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 8:
      if (lookahead == 'L') ADVANCE(11);
      END_STATE();
    case 9:
      if (lookahead == 'O') ADVANCE(22);
      if (lookahead == 'R') ADVANCE(13);
      END_STATE();
    case 10:
      if (lookahead == 'R') ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == 'S') ADVANCE(4);
      END_STATE();
    case 12:
      if (lookahead == 'T') ADVANCE(23);
      END_STATE();
    case 13:
      if (lookahead == 'U') ADVANCE(5);
      END_STATE();
    case 14:
      if (lookahead == 'X') ADVANCE(12);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 16:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym__newline);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_FOR);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_FOR);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_TO);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_NEXT);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_NEXT);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(31);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(38);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(33);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(21);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(37);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'S') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(24);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'U') ADVANCE(30);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'X') ADVANCE(36);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym__true);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym__true);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym__false);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym__false);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(39);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 1},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 7},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 16},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 16},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 16},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 16},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 7},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 16},
};

static uint16_t ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [anon_sym_NEXT] = ACTIONS(1),
    [sym__true] = ACTIONS(1),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_TO] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [sym__false] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_FOR] = ACTIONS(1),
  },
  [1] = {
    [sym_declaration] = STATE(4),
    [sym__for] = STATE(4),
    [sym__definition] = STATE(4),
    [sym__statement] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(4),
    [sym_source_file] = STATE(5),
    [sym_identifier] = ACTIONS(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_FOR] = ACTIONS(7),
  },
  [2] = {
    [sym__expression] = STATE(7),
    [sym_bool] = STATE(7),
    [sym__true] = ACTIONS(9),
    [sym_number] = ACTIONS(11),
    [sym__false] = ACTIONS(9),
    [sym_identifier] = ACTIONS(13),
  },
  [3] = {
    [anon_sym_EQ] = ACTIONS(15),
  },
  [4] = {
    [sym_declaration] = STATE(9),
    [sym__for] = STATE(9),
    [sym__definition] = STATE(9),
    [sym__statement] = STATE(9),
    [aux_sym_source_file_repeat1] = STATE(9),
    [sym_identifier] = ACTIONS(3),
    [ts_builtin_sym_end] = ACTIONS(17),
    [anon_sym_FOR] = ACTIONS(7),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(19),
  },
  [6] = {
    [anon_sym_TO] = ACTIONS(21),
  },
  [7] = {
    [anon_sym_TO] = ACTIONS(23),
  },
  [8] = {
    [sym__expression] = STATE(12),
    [sym_bool] = STATE(12),
    [sym_method_call] = STATE(12),
    [sym__true] = ACTIONS(25),
    [sym_number] = ACTIONS(27),
    [sym__false] = ACTIONS(25),
    [sym_identifier] = ACTIONS(29),
  },
  [9] = {
    [sym_declaration] = STATE(9),
    [sym__for] = STATE(9),
    [sym__definition] = STATE(9),
    [sym__statement] = STATE(9),
    [aux_sym_source_file_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(31),
    [anon_sym_FOR] = ACTIONS(33),
    [sym_identifier] = ACTIONS(36),
  },
  [10] = {
    [sym_identifier] = ACTIONS(39),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(41),
    [anon_sym_LPAREN] = ACTIONS(43),
    [anon_sym_FOR] = ACTIONS(45),
    [sym_identifier] = ACTIONS(45),
  },
  [12] = {
    [ts_builtin_sym_end] = ACTIONS(47),
    [anon_sym_FOR] = ACTIONS(49),
    [sym_identifier] = ACTIONS(49),
  },
  [13] = {
    [sym__newline] = ACTIONS(51),
  },
  [14] = {
    [sym_identifier] = ACTIONS(53),
  },
  [15] = {
    [sym__statement] = STATE(18),
    [sym_declaration] = STATE(18),
    [aux_sym__for_repeat1] = STATE(18),
    [anon_sym_NEXT] = ACTIONS(55),
    [sym_identifier] = ACTIONS(57),
  },
  [16] = {
    [anon_sym_RPAREN] = ACTIONS(59),
  },
  [17] = {
    [sym_identifier] = ACTIONS(61),
  },
  [18] = {
    [sym__statement] = STATE(22),
    [sym_declaration] = STATE(22),
    [aux_sym__for_repeat1] = STATE(22),
    [anon_sym_NEXT] = ACTIONS(63),
    [sym_identifier] = ACTIONS(57),
  },
  [19] = {
    [ts_builtin_sym_end] = ACTIONS(65),
    [anon_sym_FOR] = ACTIONS(67),
    [sym_identifier] = ACTIONS(67),
  },
  [20] = {
    [ts_builtin_sym_end] = ACTIONS(69),
    [anon_sym_FOR] = ACTIONS(71),
    [sym_identifier] = ACTIONS(71),
  },
  [21] = {
    [sym_identifier] = ACTIONS(73),
  },
  [22] = {
    [sym__statement] = STATE(22),
    [sym_declaration] = STATE(22),
    [aux_sym__for_repeat1] = STATE(22),
    [anon_sym_NEXT] = ACTIONS(75),
    [sym_identifier] = ACTIONS(77),
  },
  [23] = {
    [ts_builtin_sym_end] = ACTIONS(80),
    [anon_sym_FOR] = ACTIONS(82),
    [sym_identifier] = ACTIONS(82),
  },
  [24] = {
    [ts_builtin_sym_end] = ACTIONS(21),
    [anon_sym_FOR] = ACTIONS(84),
    [sym_identifier] = ACTIONS(84),
  },
  [25] = {
    [anon_sym_NEXT] = ACTIONS(45),
    [anon_sym_LPAREN] = ACTIONS(86),
    [sym_identifier] = ACTIONS(45),
  },
  [26] = {
    [anon_sym_NEXT] = ACTIONS(49),
    [sym_identifier] = ACTIONS(49),
  },
  [27] = {
    [anon_sym_NEXT] = ACTIONS(67),
    [sym_identifier] = ACTIONS(67),
  },
  [28] = {
    [anon_sym_NEXT] = ACTIONS(84),
    [sym_identifier] = ACTIONS(84),
  },
  [29] = {
    [sym__expression] = STATE(26),
    [sym_bool] = STATE(26),
    [sym_method_call] = STATE(26),
    [sym__true] = ACTIONS(88),
    [sym_number] = ACTIONS(90),
    [sym__false] = ACTIONS(88),
    [sym_identifier] = ACTIONS(92),
  },
  [30] = {
    [anon_sym_RPAREN] = ACTIONS(94),
  },
  [31] = {
    [anon_sym_EQ] = ACTIONS(96),
  },
  [32] = {
    [sym_identifier] = ACTIONS(98),
  },
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = false}, SHIFT(3),
  [5] = {.count = 1, .reusable = true}, REDUCE(sym_source_file, 0),
  [7] = {.count = 1, .reusable = false}, SHIFT(2),
  [9] = {.count = 1, .reusable = false}, SHIFT(6),
  [11] = {.count = 1, .reusable = true}, SHIFT(7),
  [13] = {.count = 1, .reusable = false}, SHIFT(7),
  [15] = {.count = 1, .reusable = true}, SHIFT(8),
  [17] = {.count = 1, .reusable = true}, REDUCE(sym_source_file, 1),
  [19] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
  [21] = {.count = 1, .reusable = true}, REDUCE(sym_bool, 1),
  [23] = {.count = 1, .reusable = true}, SHIFT(10),
  [25] = {.count = 1, .reusable = false}, SHIFT(24),
  [27] = {.count = 1, .reusable = true}, SHIFT(12),
  [29] = {.count = 1, .reusable = false}, SHIFT(11),
  [31] = {.count = 1, .reusable = true}, REDUCE(aux_sym_source_file_repeat1, 2),
  [33] = {.count = 2, .reusable = false}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [36] = {.count = 2, .reusable = false}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [39] = {.count = 1, .reusable = true}, SHIFT(13),
  [41] = {.count = 1, .reusable = true}, REDUCE(sym__expression, 1),
  [43] = {.count = 1, .reusable = true}, SHIFT(14),
  [45] = {.count = 1, .reusable = false}, REDUCE(sym__expression, 1),
  [47] = {.count = 1, .reusable = true}, REDUCE(sym_declaration, 3),
  [49] = {.count = 1, .reusable = false}, REDUCE(sym_declaration, 3),
  [51] = {.count = 1, .reusable = true}, SHIFT(15),
  [53] = {.count = 1, .reusable = true}, SHIFT(16),
  [55] = {.count = 1, .reusable = false}, SHIFT(17),
  [57] = {.count = 1, .reusable = false}, SHIFT(31),
  [59] = {.count = 1, .reusable = true}, SHIFT(19),
  [61] = {.count = 1, .reusable = true}, SHIFT(20),
  [63] = {.count = 1, .reusable = false}, SHIFT(21),
  [65] = {.count = 1, .reusable = true}, REDUCE(sym_method_call, 4),
  [67] = {.count = 1, .reusable = false}, REDUCE(sym_method_call, 4),
  [69] = {.count = 1, .reusable = true}, REDUCE(sym__for, 7),
  [71] = {.count = 1, .reusable = false}, REDUCE(sym__for, 7),
  [73] = {.count = 1, .reusable = true}, SHIFT(23),
  [75] = {.count = 1, .reusable = false}, REDUCE(aux_sym__for_repeat1, 2),
  [77] = {.count = 2, .reusable = false}, REDUCE(aux_sym__for_repeat1, 2), SHIFT_REPEAT(31),
  [80] = {.count = 1, .reusable = true}, REDUCE(sym__for, 8),
  [82] = {.count = 1, .reusable = false}, REDUCE(sym__for, 8),
  [84] = {.count = 1, .reusable = false}, REDUCE(sym_bool, 1),
  [86] = {.count = 1, .reusable = true}, SHIFT(32),
  [88] = {.count = 1, .reusable = false}, SHIFT(28),
  [90] = {.count = 1, .reusable = true}, SHIFT(26),
  [92] = {.count = 1, .reusable = false}, SHIFT(25),
  [94] = {.count = 1, .reusable = true}, SHIFT(27),
  [96] = {.count = 1, .reusable = true}, SHIFT(29),
  [98] = {.count = 1, .reusable = true}, SHIFT(30),
};

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_the_language_name(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
