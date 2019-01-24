#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "State.h"

template<class entity_type>
class StateMachine {
private:
	std::shared_ptr<entity_type> pOwner;
	std::shared_ptr<State<entity_type>> pCurrentState;

public:
	StateMachine(std::shared_ptr<entity_type> owner) :pOwner(owner), pCurrentState(NULL) {};
	void SetCurrentState(std::shared_ptr<State<entity_type>> s) { pCurrentState = s };

	void Update() {
		if (pCurrentState) pCurrentState->ExecuteUpdate(pOwner);
	};

	void Draw() {
		if (pCurrentState) pCurrentState->ExecuteDraw(pOwner);
	};
	

	void ChangeState(std::shared_ptr<State<entity_type>> pNewState) {
		assert(pNewState && "<StateMachine::ChangeState>: trying to change to a null state");

		pCurrentState->ExecuteExit(pOwner);
		pCurrentState = pNewState;
		pCurrentState->ExecuteEnter(pOwner);
	}

	std::shared_ptr<State<entity_type>> GetCurrentState() { return pCurrentState; }

};
