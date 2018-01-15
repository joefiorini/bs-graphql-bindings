[@bs.module "graphql-tools"]
external makeExecutableSchema :
  {
    .
    "typeDefs": string,
    "resolvers": Js.t('a)
  } =>
  GraphQL.Type.schema =
  "makeExecutableSchema";
