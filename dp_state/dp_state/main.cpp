//
//  main.cpp
//  dp_state
//
//  Created by Peter.Li on 2014/9/23.
//  Copyright (c) 2014年 Peter.Li. All rights reserved.
//

#include <iostream>
#include <memory>

class ClassicState {
public:
    enum State {
        WALK = 0,
        RUN = 1,
        SLEEP = 2,
    };
    
    void setState(State state) {
        this->_state = state;
    }
    
    void doAction() {
        std::string str;
        switch (_state) {
                case WALK: str = "Classic Action Walk"; break;
                case RUN: str = "Classic Action Run"; break;
                case SLEEP: str = "Classic Action Sleep"; break;
        }
        std::cout << str << std::endl;
    }
    
    void doPreAction() {
        std::string str;
        switch (_state) {
            case WALK: str = "Classic PreAction Walk"; break;
            case RUN: str = "Classic PreAction Run"; break;
            case SLEEP: str = "Classic PreAction Sleep"; break;
        }
        std::cout << str << std::endl;
    }
    
    void doPostAction() {
        std::string str;
        switch (_state) {
            case WALK: str = "Classic PostAction Walk"; break;
            case RUN: str = "Classic PostAction Run"; break;
            case SLEEP: str = "Classic PostAction Sleep"; break;
        }
        std::cout << str << std::endl;
    }
    
private:
    State _state = WALK;
};

class DPState {
public:
    enum State {
        WALK = 0,
        RUN = 1,
        SLEEP = 2,
    };
    
    void setState(State state) {
        switch (state) {
                case WALK: _ptr_action = std::make_shared<ActionWalk>(); break;
                case RUN: _ptr_action = std::make_shared<ActionRun>(); break;
                case SLEEP: _ptr_action = std::make_shared<ActionSleep>(); break;
            default: _ptr_action = std::make_shared<ActionWalk>();
        }
    }
    
    void doAction() {
        std::cout << _ptr_action->action() << std::endl;
    }
    
    void doPreAction() {
        std::cout << _ptr_action->preaction() << std::endl;
    }
    
    void doPostAction() {
        std::cout << _ptr_action->postaction() << std::endl;
    }
    
    
protected:
    class AbstractAction {
    public:
        virtual std::string action() = 0;
        virtual std::string preaction() = 0;
        virtual std::string postaction() = 0;
    };
    
    class ActionWalk : public AbstractAction {
    public:
        std::string action() { return "DP_State Action Walk";}
        std::string preaction() {return "DP_State PreAction Walk";}
        std::string postaction() {return "DP_State PostAction Walk";}
    };
    
    class ActionRun : public AbstractAction {
    public:
        std::string action() { return "DP_State Action Run";}
        std::string preaction() {return "DP_State PreAction Run";}
        std::string postaction() {return "DP_State PostAction Run";}
    };
    
    class ActionSleep : public AbstractAction {
    public:
        std::string action() { return "DP_State Action Sleep";}
        std::string preaction() {return "DP_State PreAction Sleep";}
        std::string postaction() {return "DP_State PostAction Sleep";}
    };
    
private:
    std::shared_ptr<AbstractAction> _ptr_action = std::make_shared<ActionWalk>();
};

template<class ActionType>
void runAllAction(ActionType& action) {
    action.doAction();
    action.doPreAction();
    action.doPostAction();
}

template<class ActionType>
void runActionState(ActionType& action) {

    action.setState(ActionType::State::WALK);
    runAllAction(action);
    
    action.setState(ActionType::State::RUN);
    runAllAction(action);
    
    action.setState(ActionType::State::SLEEP);
    runAllAction(action);
    
}


int main(int argc, const char * argv[]) {
    
    ClassicState classic_state;
    DPState dp_state;
    
    std::cout << "Run classic state method" << std::endl;
    runActionState(classic_state);
    
    std::cout << std::endl << std::endl;
    
    std::cout << "Run state pattern method" << std::endl;
    runActionState(dp_state);
    
    return 0;
}




