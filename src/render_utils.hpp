#pragma once

// instead iostream
#include <fmt/base.h>

// DirectX headers
#include <DirectXMath.h>
#include <SimpleMath.h>
#include <DirectXCollision.h>

#include <d3d12.h>
#include <dxcapi.h>
#include <wrl.h>
#include <comdef.h>
#include <directx/d3dx12.h>
#include <DDSTextureLoader.h>

// some relation with stl and eastl for better performance 
// main containers for app 
#include <EASTL/vector.h>
#include <EASTL/unordered_map.h>
#include <EASTL/map.h>
#include <EASTL/stack.h>
#include <EASTL/queue.h>
#include <EASTL/deque.h>

#include <vector>

// mem stuff 
#include <EASTL/unique_ptr.h>
#include <EASTL/shared_ptr.h>
#include <EASTL/weak_ptr.h>

using namespace Microsoft::WRL;
using namespace DirectX::SimpleMath;

inline void THROW_IF_FAILED(HRESULT res) {

	if (FAILED(res))
	{
		_com_error err(res);
		fmt::print("{}", err.ErrorMessage());
		throw std::exception("FAILED");
	}
	
}


class Render {

public:

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void shutdown() = 0;

	Render(const Render& other) = delete;
	Render& operator=(const Render& other) = delete;
	virtual ~Render() = default;
};


