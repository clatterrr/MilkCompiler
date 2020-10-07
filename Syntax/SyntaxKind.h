#pragma once
enum class SyntaxKind
{
	UnDefined,
	NumberToken,
	VariableToken,//非赋值语句
	WhitespaceToken,
	EndOfFile,
	//Operator Token
	PlusToken,
	MinusToken,
	StarToken,
	SlashToken,
	NOTToken,
	EqualToken,
	OpenParenthesisToken,
	CloseParenthesisToken,

	//Expression
	ThesisExpression,
	BinaryExpression,
	UnaryExpression,

	//KeyWord
	IntKeyWord,
	IfKeyWord,
	IdentifierToken,//变量名
	PrintKeyWord,

	//Declaration and Statement for SyntaxNode ,ExpressionSyntax,StatementSyntax
	VariableDeclaration,
	IfStatement,
	AssignStatement,
	PrintStatement

};