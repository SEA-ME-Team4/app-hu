/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_COMMONAPI_BRAKE_STATUS_SOMEIP_STUB_ADAPTER_HPP_
#define V1_COMMONAPI_BRAKE_STATUS_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/commonapi/BrakeStatusStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

template <typename _Stub = ::v1::commonapi::BrakeStatusStub, typename... _Stubs>
class BrakeStatusSomeIPStubAdapterInternal
    : public virtual BrakeStatusStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< BrakeStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> BrakeStatusSomeIPStubAdapterHelper;

    ~BrakeStatusSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        BrakeStatusSomeIPStubAdapterHelper::deinit();
    }

    void fireBrakeAttributeChanged(const bool &_value);
    
    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::BrakeStatusStub,
        CommonAPI::Version
    > getBrakeStatusInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::BrakeStatusStub,
        bool
    > getBrakeAttributeStubDispatcher;
    
    CommonAPI::SomeIP::SetObservableAttributeStubDispatcher<
        ::v1::commonapi::BrakeStatusStub,
        bool
    > setBrakeAttributeStubDispatcher;
    
    BrakeStatusSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        BrakeStatusSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< BrakeStatusStub>(_stub)),
        getBrakeStatusInterfaceVersionStubDispatcher(&BrakeStatusStub::lockInterfaceVersionAttribute, &BrakeStatusStub::getInterfaceVersion, false, true),
        getBrakeAttributeStubDispatcher(
            &::v1::commonapi::BrakeStatusStub::lockBrakeAttribute,
            &::v1::commonapi::BrakeStatusStub::getBrakeAttribute,
            false,
            _stub->hasElement(0)),
        setBrakeAttributeStubDispatcher(
            &::v1::commonapi::BrakeStatusStub::lockBrakeAttribute,
            &::v1::commonapi::BrakeStatusStub::getBrakeAttribute,
            &BrakeStatusStubRemoteEvent::onRemoteSetBrakeAttribute,
            &BrakeStatusStubRemoteEvent::onRemoteBrakeAttributeChanged,
            &BrakeStatusStubAdapter::fireBrakeAttributeChanged,
            false,
            _stub->hasElement(0))
    {
        BrakeStatusSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x1770) }, &getBrakeAttributeStubDispatcher );
        BrakeStatusSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x1771) }, &setBrakeAttributeStubDispatcher );
        std::shared_ptr<CommonAPI::SomeIP::ClientId> itsClient = std::make_shared<CommonAPI::SomeIP::ClientId>(0xFFFF, 0xFFFFFFFF, 0xFFFFFFFF);

        // Provided events/fields
        if (_stub->hasElement(0)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x8124)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x8124), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
            fireBrakeAttributeChanged(std::dynamic_pointer_cast< ::v1::commonapi::BrakeStatusStub>(_stub)->getBrakeAttribute(itsClient));
        }

    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void BrakeStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireBrakeAttributeChanged(const bool &_value) {
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            bool
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x8124),
        false,
        _value
    );
}


template <typename _Stub, typename... _Stubs>
void BrakeStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {
}

template <typename _Stub, typename... _Stubs>
void BrakeStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {
}

template <typename _Stub = ::v1::commonapi::BrakeStatusStub, typename... _Stubs>
class BrakeStatusSomeIPStubAdapter
    : public BrakeStatusSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    BrakeStatusSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          BrakeStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v1

#endif // V1_COMMONAPI_Brake_Status_SOMEIP_STUB_ADAPTER_HPP_
