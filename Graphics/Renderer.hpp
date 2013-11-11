#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <QOpenGLFunctions>
#include <QGLShaderProgram>
#include <QGLFramebufferObject>
#include <QOpenGLBuffer>
#include <vector>

#include "ModelLoader.hpp"
#include "Object.hpp"
#include "Camera.hpp"

class Renderer
{
public:
    Renderer();

    void render(std::vector<graphics::Object> renderObjects);
    void repaint(void);

    std::vector<graphics::Object> renderList;

    QMatrix4x4 pMatrix;

    graphics::Camera *cam;
    
private:
};

#endif // RENDERER_HPP
