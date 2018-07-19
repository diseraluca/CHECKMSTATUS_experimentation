// Copyright 2018 Luca Di Sera
//		Contact: disera.luca@gmail.com
//				 https://github.com/diseraluca
//				 https://www.linkedin.com/in/luca-di-sera-200023167
//
// This code is licensed under the MIT License. 
// More informations can be found in the LICENSE file in the root folder of this repository
//
//
// File : UselessyExpensiveDeformer.cpp

#include "UselessyExpensiveDeformer.h"

MString UselessyExpensiveDeformer::typeName{ "UselessyExpensiveDeformer" };
MTypeId UselessyExpensiveDeformer::typeId{ 0x0000001 };

MObject UselessyExpensiveDeformer::animateMe;

void * UselessyExpensiveDeformer::creator()
{
	return new UselessyExpensiveDeformer();
}

MStatus UselessyExpensiveDeformer::initialize()
{
	return MStatus();
}

MStatus UselessyExpensiveDeformer::deform(MDataBlock & block, MItGeometry & iterator, const MMatrix & matrix, unsigned int multiIndex)
{
	return MStatus();
}
