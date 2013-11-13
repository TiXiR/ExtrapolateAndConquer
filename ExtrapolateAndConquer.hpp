#ifndef EXTRAPOLATEANDCONQUER_HPP
#define EXTRAPOLATEANDCONQUER_HPP

#include <QApplication>
#include <QTimer>
#include <vector>

#include "Graphics/Object.hpp"
#include "Graphics/GraphicsWindow.hpp"
#include "Graphics/Model.hpp"

#include "EntitySystem/EntitySystem.hpp"
#include "Components/Components.hpp"
#include "Systems/Systems.hpp"

#include "Graphics/Renderer.hpp"

#include "ResourceManager.hpp"
#include "Graphics/WorldGen.hpp"

class ExtrapolateAndConquer : QObject
{
    Q_OBJECT

public:
    ExtrapolateAndConquer(int argc, char *argv[]);
    ~ExtrapolateAndConquer();

    void initialize(void);

    int run();
public slots:
    void loopBody();

public:

    ResourceManager rm;

    EntityManager<Components> entityManager;

    SimplePhysicsSystem simplePhysicsSystem;
    GraphicsUpdateSystem graphicsUpdateSystem;

    QApplication* application;
    GraphicsWindow* graphicsWindow;
    Camera* cam;

    QTimer* timer;

    void loadResources(void);
};

#endif // EXTRAPOLATEANDCONQUER_HPP
