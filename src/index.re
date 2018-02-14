let products = [|
  {name: "Football", price: 49.99},
  {name: "Basebll", price: 1.99},
  {name: "Poker", price: 33.99}
|];

ReactDOMRe.renderToElementWithId(
    <ProductTable products />
);

