let component = ReasonReact.statelessComponent("ProductCategoryRow");

let make = (~title: string, ~productRows, _children) => {
  ...component,
  render: (_self) => {
    <div>
        <th>{ReasonReact.stringToElement(title)}</th>
    </div>
  }
};