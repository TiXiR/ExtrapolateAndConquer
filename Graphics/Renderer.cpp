#include "Renderer.hpp"

Renderer::Renderer(void){
    cam = new Camera();

}

void Renderer::drawObject(Object* o){
    this->renderList.push_back(o);
}

void Renderer::repaint(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);

    if(skybox != NULL){
    	skybox->draw(cam->skyboxMatrix(),pMatrix);
    }

    glEnable(GL_DEPTH_TEST);

    if(world != NULL){
        world->draw(cam->vMatrix,pMatrix);
    }

    if(water != NULL){
        water->draw(cam->vMatrix,pMatrix);
    }

    for(Object * o : renderList){
        printf("Pointer to object is: %x \n",o);
        o->draw(cam->vMatrix,pMatrix);
    }

    glEnable(GL_CULL_FACE);
}
