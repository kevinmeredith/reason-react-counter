type email = Email (string);

type user = Username (string);

type action =
 | UpdateEmail (email)
 | UpdateUsername (user);

type state = {
    email: email,
    username: user
};

let component = ReasonReact.reducerComponent("Form");

/* Not needed, but investigating how to get value from event */
let getEventValue: ReactEventRe.Keyboard.t => string = (event) =>
    ReactDOMRe.domElementToObj(ReactEventRe.Keyboard.target(event))##value;

let make = (_children) => {
  ...component,
  initialState: ()         => {email : Email(""), username: Username("")},
  reducer: (action, state) => {
    switch (action) {
      | UpdateEmail(e)    => ReasonReact.Update({...state, email: e})
      | UpdateUsername(u) => ReasonReact.Update({...state, username: u})
    }
  },
  render: (_self)            => {
        <div>
            <form style=(ReactDOMRe.Style.make(~display="block", ())) >
              <label>{ReasonReact.stringToElement("Email")}
                <input name="email" _type="text" />
              </label>
              <label>{ReasonReact.stringToElement("Username")}
                <input name="username" _type="text" />
              </label>
            </form>
        </div>
  }
};