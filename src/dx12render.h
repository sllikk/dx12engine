#pragma once
#include "render_utils.hpp"


class DX12Render : public Render {


public:

	DX12Render(const DX12Render& other) = delete;

	


	// Inherited via Render
	void init() override;

	void update() override;

	void render() override;

	void shutdown() override;

};
