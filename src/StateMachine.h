#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "State.h"

template<class entity_type>
class StateMachine {
private:
	entity_type* m_pOwner;
	State<entity_type>* m_pCurrentState;

public:
	StateMachine(entity_type* owner) :m_pOwner(owner), m_pCurrentState(NULL) {};

	~StateMachine() {
		delete m_pOwner;
		delete m_pCurrentState;
	}

	void SetCurrentState(State<entity_type>* s) { m_pCurrentState = s; }

	void Update() {
		if (m_pCurrentState) m_pCurrentState->ExecuteUpdate(m_pOwner);
	};

	void Draw() {
		if (m_pCurrentState) m_pCurrentState->ExecuteDraw(m_pOwner);
	};
	

	void ChangeState(State<entity_type>* pNewState) {
		assert(pNewState && "<StateMachine::ChangeState>: trying to change to a null state");

		m_pCurrentState->ExecuteExit(m_pOwner);
		m_pCurrentState = pNewState;
		m_pCurrentState->ExecuteEnter(m_pOwner);
	}
};
