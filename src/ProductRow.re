let component = ReasonReact.statelessComponent("ProductRow");

let echo = ReasonReact.stringToElement;

let make = (~name: string, ~price: float, _) => {
 ...component,
 render: (_) => {
    <tr>
     <td>{echo(name)}</td>
     <td>{price |> string_of_float |> echo}</td>
    </tr>
 }
};