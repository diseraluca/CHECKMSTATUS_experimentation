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

#include <maya/MFnNumericAttribute.h>

MString UselessyExpensiveDeformerWithCheck::typeName{ "UselessyExpensiveDeformerWithCheck" };
MTypeId UselessyExpensiveDeformerWithCheck::typeId{ 0x0000002 };

MObject UselessyExpensiveDeformerWithCheck::animateMe;

void * UselessyExpensiveDeformerWithCheck::creator()
{
	return new UselessyExpensiveDeformerWithCheck();
}

MStatus UselessyExpensiveDeformerWithCheck::initialize()
{
	MStatus status{};

	MFnNumericAttribute nAttr;

	animateMe = nAttr.create("animateMe", "anm", MFnNumericData::kDouble, 0.0, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	CHECK_MSTATUS(nAttr.setKeyable(true));
	CHECK_MSTATUS(addAttribute(animateMe));

	CHECK_MSTATUS(attributeAffects(animateMe, outputGeom));

	return MStatus::kSuccess;
}

MStatus UselessyExpensiveDeformerWithCheck::deform(MDataBlock & block, MItGeometry & iterator, const MMatrix & matrix, unsigned int multiIndex)
{
	return MStatus();
}
