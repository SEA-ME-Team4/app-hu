/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/BatteryToHandlerSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createBatteryToHandlerSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< BatteryToHandlerSomeIPProxy>(_address, _connection);
}

void initializeBatteryToHandlerSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.BatteryToHandler:v1_0:BatteryToHandler",
        0x2, 0x16, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.BatteryToHandler:v1_0",
        &createBatteryToHandlerSomeIPProxy);
}

INITIALIZER(registerBatteryToHandlerSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeBatteryToHandlerSomeIPProxy);
}

BatteryToHandlerSomeIPProxy::BatteryToHandlerSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          batteryStatusEvent_(*this, 0x8004, CommonAPI::SomeIP::event_id_t(0x8004), CommonAPI::SomeIP::event_type_e::ET_EVENT , CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, std::make_tuple(static_cast< CommonAPI::EmptyDeployment* >(nullptr)))
{
}

BatteryToHandlerSomeIPProxy::~BatteryToHandlerSomeIPProxy() {
    completed_.set_value();
}


BatteryToHandlerSomeIPProxy::BatteryStatusEventEvent& BatteryToHandlerSomeIPProxy::getBatteryStatusEventEvent() {
    return batteryStatusEvent_;
}

void BatteryToHandlerSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> BatteryToHandlerSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1
