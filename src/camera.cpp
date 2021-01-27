#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

glm::mat4 Camera::viewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::processKeyboard(Movement direction, double deltaTime)
{
    float velocity = static_cast<float>(MovementSpeed * deltaTime);

    if (direction == Movement::FORWARD) {
        Position += Front * velocity;
    }

    if (direction == Movement::BACKWARD) {
        Position -= Front * velocity;
    }

    if (direction == Movement::LEFT) {
        Position -= Right * velocity;
    }

    if (direction == Movement::RIGHT) {
        Position += Right * velocity;
    }
}

void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;
    Yaw   += xoffset;
    Pitch += yoffset;

    if (constrainPitch) {
        if (Pitch > 89.0f) {
            Pitch = 89.0f;
        }

        if (Pitch < -89.0f) {
            Pitch = -89.0f;
        }
    }

    updateCameraVectors();
}

void Camera::processMouseScroll(float yoffset)
{
    Zoom -= yoffset;

    if (Zoom < 1.0f) {
        Zoom = 1.0f;
    }

    if (Zoom > 45.0f) {
        Zoom = 45.0f;
    }
}

void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = glm::cos(glm::radians(Yaw)) * glm::cos(glm::radians(Pitch));
    front.y = glm::sin(glm::radians(Pitch));
    front.z = glm::sin(glm::radians(Yaw)) * glm::cos(glm::radians(Pitch));
    Front = glm::normalize(front);

    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up    = glm::normalize(glm::cross(Right, Front));
}
