let component = ReasonReact.statelessComponent("ProductTable");

let echo = ReasonReact.stringToElement;

let make = (~products, _) => {
    ...component,
    render: (_) => {
      let productRows = products
        |> Array.map(({name, price}) => <ProductRow key=name name price />)
        |> ReasonReact.arrayToElement;

      <table>
        <thead>
          <tr>
            <th>{echo("Name")}</th>
            <th>{echo("Price")}</th>
          </tr>
        </thead>
        <tbody>productRows</tbody>
      </table>
    }
};