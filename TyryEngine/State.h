#pragma once
#include "AssetManager.h"
#include "Error.h"
#include <memory>

class State
{
public:
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void OnPause() {};
	virtual void OnResume() {};

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	std::unique_ptr<AssetManager> assetManager;
};

