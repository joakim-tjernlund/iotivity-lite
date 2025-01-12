/*
// Copyright 2018 Oleksandr Grytsov
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#ifndef OCINSTANCE_HPP_
#define OCINSTANCE_HPP_

#include <common/tasklet.hpp>
#include <common/timer.hpp>

class ocInstance {
public:
  ocInstance();

  static ocInstance *GetInstance();

  void PollRequest();

private:
  ot::Tasklet mPollRequest;
  ot::TimerMilli mPollTimer;
  static ocInstance *sInstance;

  static void HandlePollRequest(ot::Tasklet &aTasklet);
  static void HandlePollTimer(ot::Timer &aTimer);

  void onPollRequest();
  void onPollTimer();
};

#endif
