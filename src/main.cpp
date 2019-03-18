/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main file
*/

#include <SFML/Audio.hpp>
#include "../include/Controller.hpp"
#include "../include/Window.hpp"

void set_thread_priority()
{
    pthread_t current = pthread_self();
    struct sched_param parameters;
    parameters.sched_priority = sched_get_priority_max(SCHED_FIFO);
    pthread_setschedparam(current, SCHED_FIFO, &parameters);
}

int main(int ac, char **av)
{
    Controller *controller = new Controller(av[1], atoi(av[2]));
    World *world = new World(controller);
    std::thread thread_obj(&Controller::getServerData, controller, world);
    world->initWorld();
    Window *window = new Window(world);
    sf::SoundBuffer buffer;
    sf::Sound sound;
    if (!buffer.loadFromFile("media/Star_Wars.wav"))
        raise("Error: Sound file not found");
    sound.setBuffer(buffer);
    sleep(2);
    sound.play();
    window->display();
    sound.stop();
}