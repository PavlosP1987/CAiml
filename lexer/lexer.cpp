/* 04 April 2023 */

/* The following source code is referenced to the Lexing Phase No1. */

#include <algorithm>
#include <array>
#include <variant>
#include <string_view>

enum class ReservedToken : std::uint8_t
{
	Unknown,
	
	OpParenthesisOpen,
	OpParenthesisClose,
	OpSubscriptOpen,
	OpSubscriptClose,
	
	OpArrow,
	OpColon,
	OpComma,
	OpDot,
	
	// Arithmetic operators
	OpAdd,
	OpDiv,
	OpExp,
	OpFloorDiv,
	OpMod,
	OpMul,
	OpSub,
	
	// Bitwise operators
	OpBitwiseAnd,
	OpBitwiseLeftShift,
	OpBitwiseNot,
	OpBitwiseOr,
	OpBitwiseRightShift,
	OpBitwiseXor,
	
	// Logical operators
	OpLogicalAnd,
	OpLogicalNot,
	OpLogicalOr,
	
	// Assignment operators
	OpAssign,
	OpAssignAdd,
	OpAssignDiv,
	OpAssignExp,
	OpAssignFloorDiv,
	OpAssignMod,
	OpAssignMul,
	OpAssignSub,
	
	// Bitwise assignment operators
	OpAssignBitwiseAnd,
	OpAssignBitwiseLeftShift,
	OpAssignBitwiseOr,
	OpAssignBitwiseRightShift,
	OpAssignBitwiseXor,
	
	// Comparison operators
	OpEqual,
	OpGreaterThan,
	OpGreaterThanEqual,
	OpLessThan,
	OpLessThanEqual,
	OpNotEqual,
	
	
	// new element injection() as function  ???
	// ideal new CAiml Data Types
	
	// needs work
	
	//ChatbotTable [arrayElement1]....  ???
	
	// Keywords
	KwAnd,
	KwAs,
	KwAssert,
	KwBreak,
	KwClass,
	KwContinue,
	KwContract,
	KwDef,
	KwDel,
	KwElif,
	KwElse,
	KwExcept,
	KwFalse,
	KwFinally,
	KwFor,
	KwFrom,
	KwGlobal,
	KwIf,
	KwImport,
	KwIn,
	KwIs,
	KwLambda,
	KwLet,
	KwNon,
	KwNone,
	KwNonLocal,
	KwNot,
	KwNumber,
	KwOr,
	KwPass,
	KwRaise,
	KwReturn,
	KwString,
	KwTrue,
	KwTry,
	KwWhile,
	KwWith,
	KwYield,
	
	// Number of possible reserved tokens
	Count
};

template< typename T, std::size_t N >
[[ nodiscard ]]
constexpr std::array< T, N > sort( std::array< T, N > arr ) noexcept
{
	std::sort( std::begin( arr ), std::end( arr ) );
	return arr;
}

struct StringifiedToken
{
	std::string_view tokenStr;
	ReservedToken token{ ReservedToken::Unknown };
	
	[[ nodiscard ]]
	constexpr bool operator<( StringifiedToken const & rhs ) const
	{
		return tokenStr <rhs.tokenStr;
	}
};

constexpr std::array keywords
{
	sort
	(
		std::array
		{
			StringifiedToken{ "False"	    , ReservedToken::KwFalse	},
			StringifiedToken{ "None"	    , ReservedToken::KwNone		},
			StringifiedToken{ "True"	    , ReservedToken::KwTrue		},
			StringifiedToken{ "and"		    , ReservedToken::KwAnd		},
			StringifiedToken{ "as"		    , ReservedToken::KwAs		},
			StringifiedToken{ "assert"	    , ReservedToken::KwAssert	},
			StringifiedToken{ "break"	    , ReservedToken::KwBreak	},
			StringifiedToken{ "class"	    , ReservedToken::KwClass	},
			StringifiedToken{ "continue"	, ReservedToken::KwContinue	},
			StringifiedToken{ "contract"	, ReservedToken::KwContract	},
			StringifiedToken{ "def"			, ReservedToken::KwDef		},
			StringifiedToken{ "del"			, ReservedToken::KwDel		},
			StringifiedToken{ "elif"		, ReservedToken::KwElif		},
			StringifiedToken{ "else"		, ReservedToken::KwElse		},
			StringifiedToken{ "except"		, ReservedToken::KwExcept	},
			StringifiedToken{ "finally"		, ReservedToken::KwFinally	},
			StringifiedToken{ "for"			, ReservedToken::KwFor		},
			StringifiedToken{ "from"		, ReservedToken::KwFrom		},
			StringifiedToken{ "global"		, ReservedToken::KwGlobal	},
			StringifiedToken{ "if"			, ReservedToken::KwIf		},
			StringifiedToken{ "import"		, ReservedToken::KwImport	},
			StringifiedToken{ "in"			, ReservedToken::KwIn		},
			StringifiedToken{ "is"			, ReservedToken::KwIs		},
			StringifiedToken{ "lambda"		, ReservedToken::KwLambda	},
			StringifiedToken{ "let"			, ReservedToken::KwLet		},
			StringifiedToken{ "non"			, ReservedToken::KwNon		},
			StringifiedToken{ "nonlocal"	, ReservedToken::KwNonLocal	},
			StringifiedToken{ "not"			, ReservedToken::KwNot		},
			StringifiedToken{ "num"			, ReservedToken::KwNumber	},
			StringifiedToken{ "or"			, ReservedToken::KwOr		},
			StringifiedToken{ "pass"		, ReservedToken::KwPass		},
			StringifiedToken{ "raise"		, ReservedToken::KwRaise	},
			StringifiedToken{ "return"		, ReservedToken::KwReturn	},
			StringifiedToken{ "str"			, ReservedToken::KwString	},
			StringifiedToken{ "try"			, ReservedToken::KwTry		},
			StringifiedToken{ "while"		, ReservedToken::KwWhile	},
			StringifiedToken{ "with"		, ReservedToken::KwWith		},
			StringifiedToken{ "yield"		, ReservedToken::KwYield	},
		}
	)
};

constexpr auto operators
{
	sort
	(
		std::array
		{
			StringifiedToken{ "!"	, ReservedToken::OpLogicalNot	           },
			StringifiedToken{ "!="	, ReservedToken::OpNotEqual		           },
			StringifiedToken{ "%"	, ReservedToken::OpMod		               },
			StringifiedToken{ "%="  , ReservedToken::OpAssignMod		       },
			StringifiedToken{ "&"	, ReservedToken::OpBitwiseAnd		       },
			StringifiedToken{ "&&"	, ReservedToken::OpLogicalAnd 	           },
			StringifiedToken{ "&="	, ReservedToken::OpAssignBitwiseAnd	       },
			StringifiedToken{ "("	, ReservedToken::OpParenthesisOpen	       },
			StringifiedToken{ ")"	, ReservedToken::OpParenthesisClose	       },
			StringifiedToken{ "*"	, ReservedToken::OpMul	                   },
			StringifiedToken{ "**"	, ReservedToken::OpExp		               },
			StringifiedToken{ "**="	, ReservedToken::OpAssignExp		       },
			StringifiedToken{ "*="	, ReservedToken::OpAssignMul		       },
			StringifiedToken{ "+"	, ReservedToken::OpAdd		               },
			StringifiedToken{ "+="	, ReservedToken::OpAssignAdd	           },
			StringifiedToken{ ","	, ReservedToken::OpComma	               },
			StringifiedToken{ "-"	, ReservedToken::OpSub		               },
			StringifiedToken{ "-="	, ReservedToken::OpAssignSub		       },
			StringifiedToken{ "->"	, ReservedToken::OpArrow	               },
			StringifiedToken{ "."	, ReservedToken::OpDot		               },
			StringifiedToken{ "/"	, ReservedToken::OpDiv	                   },
			StringifiedToken{ "//"	, ReservedToken::OpFloorDiv		           },
			StringifiedToken{ "//="	, ReservedToken::OpAssignFloorDiv		   },
			StringifiedToken{ "/="	, ReservedToken::OpAssignDiv	           },
			StringifiedToken{ ":"	, ReservedToken::OpColon		           },
			StringifiedToken{ "<"	, ReservedToken::OpLessThan		           },
			StringifiedToken{ "<<"	, ReservedToken::OpBitwiseLeftShift		   },
			StringifiedToken{ "<<="	, ReservedToken::OpAssignBitwiseLeftShift  },
			StringifiedToken{ "<="	, ReservedToken::OpLessThanEqual		   },
			StringifiedToken{ "="	, ReservedToken::OpAssign		           },
			StringifiedToken{ "=="	, ReservedToken::OpEqual				   },
			StringifiedToken{ ">"	, ReservedToken::OpGreaterThan			   },
			StringifiedToken{ ">="	, ReservedToken::OpGreaterThanEqual		   },
			StringifiedToken{ ">>"	, ReservedToken::OpBitwiseRightShift	   },
			StringifiedToken{ ">>="	, ReservedToken::OpAssignBitwiseRightShift },
			StringifiedToken{ "["	, ReservedToken::OpSubscriptOpen		   },
			StringifiedToken{ "]"	, ReservedToken::OpSubscriptClose		   },
			StringifiedToken{ "^"	, ReservedToken::OpBitwiseXor			   },
			StringifiedToken{ "^="	, ReservedToken::OpAssignBitwiseXor		   },
			StringifiedToken{ "|"   , ReservedToken::OpBitwiseOr			   },
			StringifiedToken{ "|="	, ReservedToken::OpAssignBitwiseOr		   },
			StringifiedToken{ "||"	, ReservedToken::OpLogicalOr			   },
			StringifiedToken{ "~"	, ReservedToken::OpBitwiseNot			   },
		}
	)
};

struct Identifier
{
	std::string name;
};

struct Indentation {};
struct Newline {};
struct Eof {};

using Number = std::uint32_t;
using String = std::string;

class Token
{
	public:
		using ValueType = std::variant< ReservedToken, Identifier, Number, String, Indentation, Newline, Eof >;
		
		Token() noexcept = default;
		
		Token( ValueType value ) : value_{ std::move( value ) } {}
		
		template< typename T>
		[[ nodiscard ]] bool is() const noexcept
		{
			return std::holds_alternative< T >( value_ );
		}
		
		template< typename T >
		[[ nodiscard ]] T const & get() const noexcept
		{
			assert( is< T >() ); // use only in tests
			return std::get< T >( value_ );
		}
		
		[[ nodiscard ]] ValueType const & value() const noexcept
		{
			return value_;
		}
		
	private:
		ValueType value_;
};

int main()
{
	return 0;
}










































