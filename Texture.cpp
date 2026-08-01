#include "Texture.h"
#include <stb/stb_image.h>

Texture::Texture(const char* imgPath) {

	stbi_set_flip_vertically_on_load(true);
	int imgWitdh, imgHeight, numCoComp;
	unsigned char* Data = stbi_load(imgPath, &imgWitdh, &imgHeight, &numCoComp, 0);

	glGenTextures(1, &ID);
	glBindTexture( GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	if(Data){
		GLenum Format;
		if(numCoComp == 4){
			Format = GL_RGBA;
		}
		else {
			Format = GL_RGB;
		}

		glTexImage2D(GL_TEXTURE_2D, 0,Format, imgWitdh, imgHeight ,0 ,Format ,GL_UNSIGNED_BYTE, Data);
	}
		
}

void Texture::Bind(GLenum TextureUnit) {
	glActiveTexture(TextureUnit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete() {
	glDeleteTextures(1, &ID);
}