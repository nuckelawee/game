#include <cstdio>
#include "resources.h"

const Graphic::Shader& ResourceManager::LoadShader(
                      const char *sName, const char *fVertShader
				    , const char *fFragShader, const char *fGeomShader)
{
	Shaders[sName] = LoadShaderFromFile(fVertShader, fFragShader, fGeomShader);
	return Shaders[sName];
}

const Graphic::Texture2D& ResourceManager::LoadTexture(const char *sName
                                                , const char *fImageFile)
{
	Textures[sName] = LoadTextureFromFile(fImageFile);
	return Textures[sName];
}	

Graphic::Texture2D ResourceManager::LoadTextureFromFile(const char *fImageFile)
{
	Graphic::Texture2D texture;
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *pixels = stbi_load(fImageFile, &width, &height, &nrChannels, 0);

	if(nrChannels == 4) {
		texture.InternalFormat = GL_RGBA;
		texture.ImageFormat = GL_RGBA;
	}

	if(!pixels) {
		printf("Error load texture %s\n", fImageFile);
	}
	texture.Generate(width, height, pixels);

	stbi_image_free(pixels);
	return texture;
}

ResourceManager::~ResourceManager()
{
	for(auto item : Shaders) {
		glDeleteProgram(item.second.programHandle);
	}
	for(auto item : Textures) {
		glDeleteTextures(1, &(item.second.texID));
	}
}

Graphic::Shader ResourceManager::LoadShaderFromFile(const char *fVertexShader
										            , const char *fFragShader
										            , const char *fGeomShader)
{
	const char *sVertCode = loadShaderAsString(fVertexShader);
	const char *sFragCode = loadShaderAsString(fFragShader);
	const char *sGeomCode = NULL;
	if(fGeomShader)
	{ sGeomCode = loadShaderAsString(fGeomShader); }

	Graphic::Shader shader;
	shader.Generate(sVertCode, sFragCode, sGeomCode);

	delete[] sVertCode;
	delete[] sFragCode;
	if(fGeomShader)
    { delete[] sGeomCode; }

	return shader;
}	

const char* ResourceManager::loadShaderAsString(const char *fFile)
{
	unsigned int file_size;
	FILE *fd = fopen(fFile, "rw");
	if(!fd) {
		fprintf(stderr, "Can't open file: %s\n", fFile);
		exit(0);
	}
	
	fseek(fd, 0, SEEK_END);
	file_size = ftello(fd);
	fseek(fd, 0, SEEK_SET);

//  printf("File '%s' size = %u\n", fFile, file_size);

	char *sCode = new char[file_size];
	fread(sCode, 1, file_size, fd);
	fclose(fd);
	return sCode;
}

const Graphic::Texture2D& ResourceManager::GetTexture(const char *sName)
{ return Textures[sName]; }

const Graphic::Shader& ResourceManager::GetShader(const char *sName)
{ return Shaders[sName]; }

void ResourceManager::DeleteShader(const char *sName)
{ glDeleteProgram(Shaders[sName].programHandle); }
	
void ResourceManager::DeleteTexture(const char *sName)
{ glDeleteTextures(1, &(Textures[sName].texID)); }


