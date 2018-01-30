let component = ReasonReact.statelessComponent("ProductRow");

let make = (~name, ~price, _children) => {
  ...component,
  render: (_self) => {
    <tr>
      <td>{ReasonReact.stringToElement(name)}</td>
      <td>{ReasonReact.stringToElement(price)}</td>
    </tr>
  }
};