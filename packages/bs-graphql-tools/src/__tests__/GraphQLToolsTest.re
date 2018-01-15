open Jest;

open ExpectJs;

let () =
  describe(
    "#makeExecutableSchema",
    () =>
      testPromise(
        "creates schemas that run correclty",
        () => {
          let typeDefs = "type Query { me: User } type User { name: String }";
          let queryResolvers = {"me": () => {"name": "reason"}};
          let userResolvers = {"name": (user) => user##name};
          let resolvers = {"Query": queryResolvers, "User": userResolvers};
          let schema =
            GraphQLTools.makeExecutableSchema({"typeDefs": typeDefs, "resolvers": resolvers});
          let source = "{ me { name } }";
          GraphQL.run(schema, source)
          |> Js.Promise.then_(
               (execResult) =>
                 Js.Promise.resolve(expect(execResult##data##me##name) |> toEqual("reason"))
             )
        }
      )
  );
