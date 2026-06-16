import axios from "axios";
import { createApi } from "./requestHandler";

interface User {
  id: number;
  name: string;
}

interface GetUsersParams {
  limit?: number;
  page?: number;
}

const api = createApi(axios.create({ baseURL: "/api" }));

export const userApi = {
  getUsers: (params?: GetUsersParams) => api.get<User[], GetUsersParams>({url: "", params}),
  getUserById: (id: number) => api.get<User>({url: `/users/${id}`}),
};

let a = userApi.getUsers({page: 10, limit: 100})
let b = userApi.getUserById(100)

console.log(a, b)