OF_GLSL_SHADER_HEADER

precision mediump float;

uniform vec2 centers[200]; // 複数の円の中心座標
uniform float radii[200]; // 各円の半径。centersに対応
uniform int numCircles = 200; // 実際に描画する円の数
uniform vec2 screenSize; // 画面のサイズ

void main()
{
    vec2 position = gl_FragCoord.xy / screenSize;
    bool insideAnyCircle = false;

    for(int i = 0; i < numCircles; i++)
    {
        float dist = distance(position, centers[i]);
        if(dist < radii[i])
        {
            insideAnyCircle = true;
            break; // 少なくとも1つの円の内部にあれば、ループを抜ける
        }
    }

    if(insideAnyCircle)
    {
        // いずれかの円の内部にある場合、白色で塗る
        gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    }
    else
    {
        // それ以外の場合、背景を黒色で塗る
        gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);
    }
}
