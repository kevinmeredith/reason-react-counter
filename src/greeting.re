type action =
 | Click
 | Toggle;

type state = {
    count: int,
    show: bool
};

let component = ReasonReact.reducerComponent("Greeting");

let make = (_children) => {
  ...component,
  initialState: ()         => { count: 0, show: false },
  reducer: (action, state) => {
    switch (action) {
      | Click  => ReasonReact.Update({...state, count: state.count + 1})
      | Toggle => ReasonReact.Update({...state, show: ! state.show})
    }
  },
  render: (self)            => {
     let message = if(self.state.show) {
         "Clicked " ++ string_of_int(self.state.count) ++ "times"
         } else {
            "hidden!"
         };
        <div>
          <button onClick={_event => self.send(Click)}>{ReasonReact.stringToElement("+")}</button>
          <button onClick={_event => self.send(Toggle)}>{{ReasonReact.stringToElement("Toggle")}}</button>
          <span>{ReasonReact.stringToElement(message)}</span>
        </div>
  }
};