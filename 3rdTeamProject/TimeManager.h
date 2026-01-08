#pragma once
class TimeManager
{
	DECLARE_SINGLE(TimeManager);

public:
	void Init();
	void Update();

	uint32 GetFps() { return _fps; }
	float GetDeltaTime() { return _deltaTime; }

	float GetTotalTime() { return _totalTime; }

	void SetStart(bool isStart) { _start = isStart; }
	bool GetStart() { return _start; }
private:
	uint64 _frequency = 0;
	uint64 _prevCount = 0;
	float _deltaTime = 0.f;

private:
	uint32 _frameCount = 0;
	float _frameTime = 0.f;
	uint32 _fps = 0;

	float _totalTime = 0.f;
	bool _start = false;
};

