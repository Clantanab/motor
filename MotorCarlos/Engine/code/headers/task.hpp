#pragma once


namespace engine 
{
	class Task
	{


	public:
		int priority = 0;

		Task(int priority = 0){	this->priority = priority;}

		struct Comparar
		{
			bool operator () (const Task* first, const Task* second) const{ return  first->priority < second->priority; }
		};

		virtual ~Task() = default;

		virtual void Run() = 0;
		virtual void Init() = 0;
		virtual void End() = 0;

		bool cmp(const Task* a, const Task* b) { return a->priority < b->priority; }
	};
}
