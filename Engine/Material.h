﻿#pragma once

// NOTE :
// 월드 상에 생성된 object의 질감, 텍스처 등 재질을 결정하는 material class
// 

class Shader;

// 빛 구조체
struct Light
{
	float ambient;
	float specular;
	int32_t shininess;
	glm::vec3 pos;
	glm::vec3 color;
	bool on{ true };
};

class Material
{
public:
	Material();
	virtual ~Material();

	void ApplyColor();
	void ApplyLight();

	glm::vec3 GetColor() { return _color; }

	void SetShader(std::shared_ptr<Shader>& shader) { _shader = shader; }
	void SetColor(glm::vec3 color) { _color = color; }
	void SetObjectColor(glm::vec3 color);

private:
	std::shared_ptr<Shader> _shader;
	glm::vec3 _color;
};
