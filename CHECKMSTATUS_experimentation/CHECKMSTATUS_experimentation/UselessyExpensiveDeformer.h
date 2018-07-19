// Copyright 2018 Luca Di Sera
//		Contact: disera.luca@gmail.com
//				 https://github.com/diseraluca
//				 https://www.linkedin.com/in/luca-di-sera-200023167
//
// This code is licensed under the MIT License. 
// More informations can be found in the LICENSE file in the root folder of this repository
//
//
// File : UselessyExpensiveDeformer.h
//
// A Maya custom deformer which does nothing apart from a somewhat heavy computation.
// Used for testing purposes.

#pragma once

#include <maya/MPxDeformerNode.h>

class UselessyExpensiveDeformer : public MPxDeformerNode {
public:
	static void* creator();
	static MStatus initialize();
	virtual MStatus deform(MDataBlock & block, MItGeometry & iterator, const MMatrix & matrix, unsigned int multiIndex) override;

public:
	static MString typeName;
	static MTypeId typeId;

	static MObject animateMe;
};