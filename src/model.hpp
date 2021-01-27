#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>

#include <assimp/scene.h>

#include "mesh.hpp"
#include "shader.hpp"

class Model
{
public:
    std::vector<Texture> textures_loaded;
    std::vector<Mesh>    meshes;
    std::string directory;
    bool gammaCorrection;

    Model(std::string const &path, bool gamma = false);

    void Draw(Shader &shader);

private:
    void loadModel(std::string const &path);

    void processNode(aiNode *node, const aiScene *scene);

    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

#endif
