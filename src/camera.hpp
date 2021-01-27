#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

#include <glm/glm.hpp>

class Camera
{
public:
    enum class Movement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);

    glm::mat4 viewMatrix();

    void processKeyboard(Movement direction, double deltaTime);

    void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

    void processMouseScroll(float yoffset);

public:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    float Yaw;
    float Pitch;

    double MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    static constexpr float YAW         = -90.0f;
    static constexpr float PITCH       =  0.0f;
    static constexpr double SPEED       =  2.5;
    static constexpr float SENSITIVITY =  0.1f;
    static constexpr float ZOOM        =  45.0f;

private:
    void updateCameraVectors();
};

#endif
