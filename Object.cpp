#include "Object.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"

Object::Object(GLfloat* vertices, GLsizeiptr vertexSize, GLuint* indices, GLsizeiptr indexSize, const char* vertexShader, const char* fragmentShader) : shader(vertexShader, fragmentShader)
{
    Position = glm::vec3(0.0f);
    Rotation = glm::vec3(0.0f);
    Scale = glm::vec3(1.0f);
    Color = glm::vec3(1.0f, 1.0f, 1.0f);
    vao.Bind();

    vbo = new VBO(vertices, vertexSize);
    ebo = new EBO(indices, indexSize);

    vao.LinkAttrib(*vbo, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
    vao.LinkAttrib(*vbo, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.LinkAttrib(*vbo, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    vao.LinkAttrib(*vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
    vao.Unbind();

    IndexCount = indexSize / sizeof(GLuint);
}

void Object::Draw(glm::mat4 view, glm::mat4 projection, glm::vec3 light_Color, glm::vec3 light_Position, glm::vec3 camera_Position) {

    shader.Active();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, Position);
    model = glm::scale(model, Scale);

    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));


    glUniform3fv(glGetUniformLocation(shader.ID, "object_Color"), 1, glm::value_ptr(Color));
    glUniform3fv(glGetUniformLocation(shader.ID, "light_Color"), 1, glm::value_ptr(light_Color));
    glUniform3fv(glGetUniformLocation(shader.ID, "light_Position"), 1, glm::value_ptr(light_Position));
    glUniform3fv(glGetUniformLocation(shader.ID, "view_Position"), 1, glm::value_ptr(camera_Position));
    vao.Bind();

    glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_INT, 0);

}
