//Original code by Kevin Ouellet
//kouellet@users.sourceforge.net
#ifndef FALCONGEOMETRY_H_
#define FALCONGEOMETRY_H_

namespace libnifalcon
{
	namespace stamper
	{	
		const static int WHEEL_SLOTS_NUMBER = 320; // Number of transparent slot on the encoder wheel, 
		const static int SHAFT_DIAMETER = 14.25f; // Diameter of the motor shaft
		const static int SMALL_ARM_DIAMETER = 110.0f; // Small diameter of the arm
		const static int THETA_OFFSET_ANGLE = 35; // When encoder value = 0 (approx)

		enum arm_id
		{
			ARM_1 = 0, ARM_2, ARM_3
		};	

		enum theta_id
		{
			THETA_1 = 0, THETA_2, THETA_3
		};

		enum coord
		{
			X = 0, Y, Z
		};

		struct Angle
		{
			float theta1[3];
			float theta2[3];
			float theta3[3];
		};

		const static float a = 60;
		const static float b = 102.5;
		const static float c = 14;
		const static float d = 11.25;
		const static float e = d;
		const static float f = -25;
		const static float s = -27.330909;
		const static float r = 37.233758;

// degrees = {90, -30, 150} -> radians = {PI/2,-PI/6,-5*PI/6}
		const static float phy[] = { gmtl::Math::PI/2, -gmtl::Math::PI/6, -5*gmtl::Math::PI/6 };
	}
}
#endif /*FALCONGEOMETRY_H_*/
