#pragma once     //为了防止头文件被重复包含

typedef struct tagVertex
{
	int row;     //行
	int col;     //列
	int info;    //信息类
}Vertex;

#define BLANK -1
#define MAX_ROW 8		//初始行数
#define MAX_COL 8		//初始列数
