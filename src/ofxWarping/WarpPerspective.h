#pragma once

#include "Warp.h"

namespace ofxWarping
{
	class WarpPerspective
		: public Warp
	{
	public:
		WarpPerspective();
		virtual ~WarpPerspective();

		const ofMatrix4x4 & getTransform();
		const ofMatrix4x4 & getTransformInverted();

		//! reset control points to undistorted image
		virtual void reset() override;
		//! setup the warp before drawing its contents
		virtual void begin() override;
		//! restore the warp after drawing
		virtual void end() override;

		//! draws a specific area of a warped texture to a specific region
		virtual void draw(const ofTexture & texture, const ofRectangle & srcBounds, const ofRectangle & dstBounds) override;
	
	protected:
		virtual void drawInterface(bool controls = true) override;

		ofMatrix4x4 getPerspectiveTransform(const ofVec2f src[4], const ofVec2f dst[4]) const;
		void gaussianElimination(float * input, int n) const;

	protected:
		ofVec2f srcPoints[4];
		ofVec2f dstPoints[4];

		ofMatrix4x4 transform;
		ofMatrix4x4 transformInverted;

		ofShader shader;
		ofVboMesh quadMesh;
	};
}