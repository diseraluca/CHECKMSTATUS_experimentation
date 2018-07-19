// Copyright 2018 Luca Di Sera
//		Contact: disera.luca@gmail.com
//				 https://github.com/diseraluca
//				 https://www.linkedin.com/in/luca-di-sera-200023167
//
// This code is licensed under the MIT License. 
// More informations can be found in the LICENSE file in the root folder of this repository
//
//
// File : UselessyExpensiveDeformerWithCheckAndReturn.cpp

#include "UselessyExpensiveDeformerWithCheckAndReturn.h"

#include <maya/MFnNumericAttribute.h>
#include <maya/MPointArray.h>
#include <maya/MItGeometry.h>

#include <cmath>

MString UselessyExpensiveDeformerWithCheckAndReturn::typeName{ "UselessyExpensiveDeformerWithCheckAndReturn" };
MTypeId UselessyExpensiveDeformerWithCheckAndReturn::typeId{ 0x0000003 };

MObject UselessyExpensiveDeformerWithCheckAndReturn::animateMe;

void * UselessyExpensiveDeformerWithCheckAndReturn::creator()
{
	return new UselessyExpensiveDeformerWithCheckAndReturn();
}

MStatus UselessyExpensiveDeformerWithCheckAndReturn::initialize()
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

MStatus UselessyExpensiveDeformerWithCheckAndReturn::deform(MDataBlock & block, MItGeometry & iterator, const MMatrix & matrix, unsigned int multiIndex)
{
	MStatus status{};
	MPointArray vertexPositions{};
	CHECK_MSTATUS_AND_RETURN_IT(iterator.allPositions(vertexPositions));

	unsigned int vertexCount{ vertexPositions.length() };
	auto start = std::chrono::high_resolution_clock::now();
	for (unsigned int vertexIndex{ 0 }; vertexIndex < vertexCount; vertexIndex++, iterator.next()) {
		MPoint point = iterator.position(MSpace::kObject, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);

		point.z = std::pow(std::pow(point.x, 8), std::floor(point.y / 8)) * 5;
		vertexPositions[vertexIndex] = point;
	}
	auto end = std::chrono::high_resolution_clock::now();

	time += end - start;
	++counter;
	if (counter >= 100) {
		std::cout << this->name() << " Sample: " << std::chrono::duration_cast<std::chrono::microseconds>(time).count() << "micros. 100 deform calls with an average of " << std::chrono::duration_cast<std::chrono::microseconds>(time / 100).count() << "micros per call." << std::endl;
		time = time.zero();
		counter = 0;
	}

	iterator.setAllPositions(vertexPositions);
	return MStatus::kSuccess;
}
