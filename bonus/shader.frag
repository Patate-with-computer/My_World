#version 120
#define PI 3.141592653589793

uniform sampler2D texture;
uniform float time;
uniform vec3 som;
uniform int is_water;

float get_atan2(float y, float x)
{
    float angle = atan(y, x);

    if (angle < 0)
        angle += 2 * PI;
    angle /= (2 * PI);
    return angle;
}

float fade(float t)
{
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float lerp(float t, float a, float b)
{
    return a + t * (b - a);
}

void main()
{
    vec2 uv = gl_TexCoord[0].st;
    float z1 = som.x;
    float z2 = som.y;
    float GRID_SIZE = som.z;
    float a = fade(fade(get_atan2(z1 - z2, -GRID_SIZE)));
    float tm = time / 350.0;
    vec4 add = vec4(0.0);

    if (is_water == 1) {
        add += vec4(sin(uv.x * 5.0 + tm)) / 25.0 + (z1 / 500.0);
        uv.x += 0.05 * sin((uv.y * 10.0 + tm) + tm);
        uv.y += 0.05 * sin((uv.x * 10.0 + tm) + tm);
    }
    gl_FragColor = vec4(texture2D(texture, uv).rgb * lerp(a, 0, 2) + add.rgb, 1.0);
}
