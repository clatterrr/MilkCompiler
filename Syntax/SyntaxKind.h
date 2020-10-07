#pragma once
enum class SyntaxKind
{
	UnDefined,
	NumberToken,
	VariableToken,//�Ǹ�ֵ���
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
	IdentifierToken,//������
	PrintKeyWord,

	//Declaration and Statement for SyntaxNode ,ExpressionSyntax,StatementSyntax
	VariableDeclaration,
	IfStatement,
	AssignStatement,
	PrintStatement

};