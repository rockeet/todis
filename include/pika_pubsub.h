// Copyright (c) 2015-present, Qihoo, Inc.  All rights reserved.
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree. An additional grant
// of patent rights can be found in the PATENTS file in the same directory.

#ifndef PIKA_PUBSUB_H_
#define PIKA_PUBSUB_H_

#include "pika_command.h"

/*
 * pubsub
 */
class PublishCmd : public Cmd {
 public:
  using Cmd::Cmd;
  void Do(const std::shared_ptr<Partition>& partition = nullptr) override;
  void Split(const std::shared_ptr<Partition>&, const HintKeys&) override {}
  void Merge() override {}
  Cmd* Clone() override { return new PublishCmd(*this); }
 private:
  std::string channel_;
  std::string msg_;
  void DoInitial() override;
};

class SubscribeCmd : public Cmd {
 public:
  using Cmd::Cmd;
  void Do(const std::shared_ptr<Partition>& partition = nullptr) override;
  void Split(const std::shared_ptr<Partition>&, const HintKeys&) override {}
  void Merge() override {}
  Cmd* Clone() override { return new SubscribeCmd(*this); }
 private:
  void DoInitial() override;
};

class UnSubscribeCmd : public Cmd {
 public:
  using Cmd::Cmd;
  void Do(const std::shared_ptr<Partition>& partition = nullptr) override;
  void Split(const std::shared_ptr<Partition>&, const HintKeys&) override {}
  void Merge() override {}
  Cmd* Clone() override { return new UnSubscribeCmd(*this); }
 private:
  void DoInitial() override;
};

class PUnSubscribeCmd : public Cmd {
 public:
  using Cmd::Cmd;
  void Do(const std::shared_ptr<Partition>& partition = nullptr) override;
  void Split(const std::shared_ptr<Partition>&, const HintKeys&) override {}
  void Merge() override {}
  Cmd* Clone() override { return new PUnSubscribeCmd(*this); }
 private:
  void DoInitial() override;
};

class PSubscribeCmd : public Cmd {
 public:
  using Cmd::Cmd;
  void Do(const std::shared_ptr<Partition>& partition = nullptr) override;
  void Split(const std::shared_ptr<Partition>&, const HintKeys&) override {}
  void Merge() override {}
  Cmd* Clone() override { return new PSubscribeCmd(*this); }
 private:
  void DoInitial() override;
};

class PubSubCmd : public Cmd {
 public:
  using Cmd::Cmd;
  void Do(const std::shared_ptr<Partition>& partition = nullptr) override;
  void Split(const std::shared_ptr<Partition>&, const HintKeys&) override {}
  void Merge() override {}
  Cmd* Clone() override { return new PubSubCmd(*this); }
 private:
  std::string subcommand_;
  std::vector<std::string > arguments_;
  void DoInitial() override;
  void Clear() override {
    arguments_.clear();
  }
};

#endif  // INCLUDE_PIKA_PUBSUB_H_
