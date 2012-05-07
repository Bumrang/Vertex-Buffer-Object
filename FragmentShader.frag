#version 330

out vec4 outputColorX;


void main()
{
	float lerpValueX = gl_FragCoord.y / 500.0f;
		outputColorX = mix(vec4(1.0f, 1.0f, 1.0f, 0.0f),
			vec4(0.0f, 0.0f, 1.0f, 1.0f), lerpValueX);
}