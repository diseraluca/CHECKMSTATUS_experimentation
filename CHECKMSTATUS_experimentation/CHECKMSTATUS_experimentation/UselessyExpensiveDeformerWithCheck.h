// Copyright 2018 Luca Di Sera
//		Contact: disera.luca@gmail.com
//				 https://github.com/diseraluca
//				 https://www.linkedin.com/in/luca-di-sera-200023167
//
// This code is licensed under the MIT License. 
// More informations can be found in the LICENSE file in the root folder of this repository
//
//
// File : UselessyExpensiveDeformerWithCheck.h
//
// A version of the UselessyExpensiveDeformers that add CHECK_MSTATUS macros to the game.

#pragma once

#include <maya/MPxDeformerNode.h>

#include <chrono>

class UselessyExpensiveDeformerWithCheck : public MPxDeformerNode {
public:
	UselessyExpensiveDeformerWithCheck() :time{}, counter{ 0 } {}

	static void* creator();
	static MStatus initialize();
	virtual MStatus deform(MDataBlock & block, MItGeometry & iterator, const MMatrix & matrix, unsigned int multiIndex) override;

public:
	static MString typeName;
	static MTypeId typeId;

	static MObject animateMe;

private:
	std::chrono::duration<double> time;
	int counter;
};