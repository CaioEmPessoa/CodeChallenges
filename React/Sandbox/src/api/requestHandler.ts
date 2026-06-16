import { type AxiosError, type AxiosInstance, type AxiosRequestHeaders, type AxiosRequestConfig } from "axios";

type RequestProps<Params, Data> =
  {url: string, params?: Params, data?: Data, headers?: AxiosRequestHeaders};

type SuccessResponse<ApiReturn> = {
  code: number;
  data: ApiReturn;
};

type ErrorResponse = {
  code: 500;
  error: AxiosError;
};

type BaseResponse<ApiReturn> = Promise<SuccessResponse<ApiReturn> | ErrorResponse>;

export function createApi(client: AxiosInstance) {
  async function request<ApiReturn>(config: AxiosRequestConfig) :
   BaseResponse<ApiReturn> {
    try {
      const res = await client.request<ApiReturn>(config);
      return { code: res.status, data: res.data };
    } catch (e) {
      return { code: 500, error: e as AxiosError };
    }
  };

  return {
    get: <ApiReturn, Params=null, Data=null>(requestData: RequestProps<Params, Data>) =>
      request<ApiReturn>({ method: "GET", ...requestData }),
    post: <ApiReturn, Params=null, Data=null>(requestData: RequestProps<Params, Data>) =>
      request<ApiReturn>({ method: "POST", ...requestData }),
  };
}