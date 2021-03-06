/* Copyright 2016 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// TODO(b/26692266): Automatically generate gRPC proto files.
// For now follow instructions in the bug.

// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: mnist_inference.proto
#ifndef GRPC_mnist_5finference_2eproto__INCLUDED
#define GRPC_mnist_5finference_2eproto__INCLUDED

#include "mnist_inference.pb.h"

#include <grpc++/support/async_stream.h>
#include <grpc++/impl/rpc_method.h>
#include <grpc++/impl/proto_utils.h>
#include <grpc++/impl/service_type.h>
#include <grpc++/support/async_unary_call.h>
#include <grpc++/support/status.h>
#include <grpc++/support/stub_options.h>
#include <grpc++/support/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace tensorflow {
namespace serving {

class MnistService GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Classify(::grpc::ClientContext* context, const ::tensorflow::serving::MnistRequest& request, ::tensorflow::serving::MnistResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tensorflow::serving::MnistResponse>> AsyncClassify(::grpc::ClientContext* context, const ::tensorflow::serving::MnistRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::tensorflow::serving::MnistResponse>>(AsyncClassifyRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::tensorflow::serving::MnistResponse>* AsyncClassifyRaw(::grpc::ClientContext* context, const ::tensorflow::serving::MnistRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::Channel>& channel);
    ::grpc::Status Classify(::grpc::ClientContext* context, const ::tensorflow::serving::MnistRequest& request, ::tensorflow::serving::MnistResponse* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tensorflow::serving::MnistResponse>> AsyncClassify(::grpc::ClientContext* context, const ::tensorflow::serving::MnistRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::tensorflow::serving::MnistResponse>>(AsyncClassifyRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::Channel> channel_;
    ::grpc::ClientAsyncResponseReader< ::tensorflow::serving::MnistResponse>* AsyncClassifyRaw(::grpc::ClientContext* context, const ::tensorflow::serving::MnistRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_Classify_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::Channel>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::SynchronousService {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Classify(::grpc::ServerContext* context, const ::tensorflow::serving::MnistRequest* request, ::tensorflow::serving::MnistResponse* response);
    ::grpc::RpcService* service() GRPC_OVERRIDE GRPC_FINAL;
   private:
    std::unique_ptr< ::grpc::RpcService> service_;
  };
  class AsyncService GRPC_FINAL : public ::grpc::AsynchronousService {
   public:
    explicit AsyncService();
    ~AsyncService() {};
    void RequestClassify(::grpc::ServerContext* context, ::tensorflow::serving::MnistRequest* request, ::grpc::ServerAsyncResponseWriter< ::tensorflow::serving::MnistResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag);
  };
};

}  // namespace serving
}  // namespace tensorflow


#endif  // GRPC_mnist_5finference_2eproto__INCLUDED
