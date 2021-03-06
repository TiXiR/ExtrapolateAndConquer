#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Model.hpp"
#include "Camera.hpp"
#include "ModelLoader.hpp"

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

namespace graphics {

class Object : protected QOpenGLFunctions
{
public:
    Object(Model* model, QOpenGLShaderProgram* program, GLuint _texture0 = 0, GLuint _texture1 = 0, GLuint _texture2 = 0);
    Object(ModelLoader* model, QOpenGLShaderProgram* program, GLuint _texture0 = 0, GLuint _texture1 = 0, GLuint _texture2 = 0);

    void setDefaultValues();

    void draw(const QMatrix4x4 &vMatrix, const QMatrix4x4 &pMatrix);
    void draw2(const QMatrix4x4 &vMatrix, const QMatrix4x4 &pMatrix);

    QOpenGLShaderProgram* program;

    void setPosition(float x, float y, float z);
    void setScale(float x, float y, float z);
    void setColor(float r, float g, float b, float a = 1);
    void setTexScaling(float scale);
    void setShadingParameters(float _ambientCoeff, float _diffuseCoeff, float _specualrCoeff, float _specularExponent);

private:
    Model* model;
    ModelLoader* model2;
    GLuint texture0, texture1, texture2;

    QVector3D position;
    QVector3D scale;
    float texScaling;

    QMatrix4x4 mMatrix;

    QVector4D color;

    float ambientCoeff;
    float diffuseCoeff;
    float specularCoeff;
    float specularExponent;
};

}

#endif // OBJECT_HPP
