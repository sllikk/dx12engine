#pragma once

#if defined USE_WIN_HEADER
#include <Windows.h>
#include <iostream>
#endif

// instead
#include <fmt/base.h>

// DirectX headers
#include <DirectXMath.h>
#include <DirectXCollision.h>
#include <d3d12.h>
#include <dxcapi.h>
#include <wrl.h>
#include <comdef.h>
#include <DirectXHelpers.h>

#include <EASTL/vector.h>

inline void THROW_IF_FAILED(HRESULT res) {
	
	if (FAILED(res))
	{
		_com_error err(res);
		fmt::print("{}", err.ErrorMessage());
		throw std::exception("FAILED");
	}

}




