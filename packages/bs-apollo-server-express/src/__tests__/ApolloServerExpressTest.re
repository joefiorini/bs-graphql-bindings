open Jest;

open ExpectJs;

let () = {
  let schema = GraphQL.Utilities.buildSchema("type Query { hello: String }");
  let rootValue = {"hello": () => "world"};
  describe(
    "#createGraphQLExpressMiddleware",
    () =>
      test(
        "creates an express middleware",
        () => {
          let middleware = ApolloServerExpress.createGraphQLExpressMiddleware(schema, ~rootValue);
          expect(middleware) |> toBeTruthy
        }
      )
  );
  describe(
    "#createGraphiQLExpressMiddleware",
    () =>
      test(
        "creates an express middleware",
        () => {
          let middleware =
            ApolloServerExpress.createGraphiQLExpressMiddleware("/graphql", ~query="{ hello }");
          expect(middleware) |> toBeTruthy
        }
      )
  )
};
