// Copyright 2018 Luca Di Sera
//		Contact: disera.luca@gmail.com
//				 https://github.com/diseraluca
//				 https://www.linkedin.com/in/luca-di-sera-200023167
//
// This code is licensed under the MIT License. 
// More informations can be found in the LICENSE file in the root folder of this repository
//
//
// File : UselessyExpensiveDeformerWithCheck.cpp

#include "UselessyExpensiveDeformerWithCheck.h"

MString UselessyExpensiveDeformerWithCheck::typeName{ "UselessyExpensiveDeformerWithCheck" };
MTypeId UselessyExpensiveDeformerWithCheck::typeId{ 0x0000002 };

MObject UselessyExpensiveDeformerWithCheck::animateMe;

void * UselessyExpensiveDeformerWithCheck::creator()
{
	return new UselessyExpensiveDeformerWithCheck();
}

MStatus UselessyExpensiveDeformerWithCheck::initialize()
{
	return MStatus();
}

MStatus UselessyExpensiveDeformerWithCheck::deform(MDataBlock & block, MItGeometry & iterator, const MMatrix & matrix, unsigned int multiIndex)
{
	return MStatus();
}
